# $NetBSD: hacks.mk,v 1.1 2021/11/29 13:54:29 pho Exp $

### [Mon Nov 29 21:58:26 JST 2021 : pho]
### ncmpcpp is an unusual program which wants to use readline and ncursesw at
### the same time, and it crashes on startup without this hack. Things get
### really complicated in this scenario:
###
### * devel/readline is linked against native libterminfo.so because it is the
###   default termcap library (see mk/termcap.buildlink3.mk). Yes, termcap. It
###   has both termcap and terminfo implementations in a single library!
###
### * /usr/lib/libtermcap.so is actually a symlink to /usr/lib/libterminfo.so.
###
### * devel/ncursesw has its own terminfo implementation and wants to use it.
###
### * Since ncmpcpp is linked with -lreadline, -ltermcap, and -lncursesw at the
###   same time, the resulting executable ends up having DT_NEEDED for both
###   libterminfo.so and libncursesw.so.
###
### * But these two libraries aren't ABI compatible. When libncursesw calls a
###   function like, say, tigetnum(), it will actually call tigetnum() in native
###   libterminfo and then segfaults.
###
### * I don't know if NetBSD ld.elf_so creates a separate namespace of symbols
###   for each library DT_NEEDED'ed. I mean, I don't know what happens if the
###   main executable of ncmpcpp didn't have a DT_NEEDED for libterminfo. Will
###   libreadline use symbols in libterminfo and libncursesw use symbols in
###   itself? A quick test indicates it's plausible. ncmpcpp at least doesn't
###   crash when this hack is applied.
###
### * The situation is supposedly the same for devel/tig. It too uses readline
###   and ncursesw at the same time. But for some reason it doesn't crash. I
###   have absolutely no idea why it doesn't.
.if ${OPSYS} == "NetBSD"
PKG_HACKS+=		libtermcap-removal
BUILDLINK_TRANSFORM+=	rm:-ltermcap
.endif
