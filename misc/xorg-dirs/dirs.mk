# $NetBSD: dirs.mk,v 1.5 2005/12/05 20:50:41 rillig Exp $
#

.if !defined(DIRS_XORG_MK)
DIRS_XORG_MK=		# defined

oldval:=		${XORG_ONLY_DIRS}
XORG_ONLY_DIRS:=	YES
XORG_ONLY_DIRS:=	${oldval}
.undef oldval

XORG_DIRS=		bin
XORG_DIRS+=		include
XORG_DIRS+=		include/X11
XORG_DIRS+=		include/X11/bitmaps
XORG_DIRS+=		lib
XORG_DIRS+=		lib/X11
XORG_DIRS+=		lib/X11/app-defaults
XORG_DIRS+=		lib/X11/config
XORG_DIRS+=		lib/X11/doc
XORG_DIRS+=		lib/X11/etc
XORG_DIRS+=		lib/X11/fonts
XORG_DIRS+=		lib/X11/fs
XORG_DIRS+=		${MAN_DIR}
XORG_DIRS+=		${LIBMAN_DIR}
XORG_DIRS+=		${KERNMAN_DIR}
XORG_DIRS+=		${FILEMAN_DIR}
XORG_DIRS+=		${MISCMAN_DIR}

.if defined(_USE_XORG_DIRS) && !empty(_USE_XORG_DIRS)
DEPENDS+=		xorg-dirs>=${_USE_XORG_DIRS}:../../misc/xorg-dirs

.  for dir in ${XORG_DIRS}
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/${dir:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in xorg-dirs: "$$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_XORG_MK)
