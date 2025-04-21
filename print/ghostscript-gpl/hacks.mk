# $NetBSD: hacks.mk,v 1.3 2025/04/21 21:14:14 wiz Exp $

### [ Thu Nov 13 12:30:45 EST 2008 : chuck]
### gs has hand-rolled shared lib handling that doesn't do the right
### thing on Darwin by default, you need to reconfigure unix-dll.mak
### to make it work.
.if ${OPSYS} == "Darwin"
post-patch:
	${SED} -e 's/^#Darwin#//' ${WRKSRC}/base/unix-dll.mak > \
		${WRKSRC}/base/unix-darwin.mak
	${MV} ${WRKSRC}/base/unix-darwin.mak ${WRKSRC}/base/unix-dll.mak
.endif
