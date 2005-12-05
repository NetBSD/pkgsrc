# $NetBSD: dirs.mk,v 1.6 2005/12/05 20:50:38 rillig Exp $
#

.if !defined(DIRS_XFREE86_MK)
DIRS_XFREE86_MK=	# defined

oldval:=		${XFREE86_ONLY_DIRS}
XFREE86_ONLY_DIRS:=	YES
XFREE86_ONLY_DIRS:=	${oldval}
.undef oldval

XFREE86_DIRS=		bin
XFREE86_DIRS+=		include
XFREE86_DIRS+=		include/X11
XFREE86_DIRS+=		include/X11/bitmaps
XFREE86_DIRS+=		lib
XFREE86_DIRS+=		lib/X11
XFREE86_DIRS+=		lib/X11/app-defaults
XFREE86_DIRS+=		lib/X11/config
XFREE86_DIRS+=		lib/X11/doc
XFREE86_DIRS+=		lib/X11/etc
XFREE86_DIRS+=		lib/X11/fonts
XFREE86_DIRS+=		lib/X11/fs
XFREE86_DIRS+=		${MAN_DIR}
XFREE86_DIRS+=		${LIBMAN_DIR}
XFREE86_DIRS+=		${KERNMAN_DIR}
XFREE86_DIRS+=		${FILEMAN_DIR}
XFREE86_DIRS+=		${MISCMAN_DIR}

.if defined(_USE_XFREE86_DIRS) && !empty(_USE_XFREE86_DIRS)
DEPENDS+=		XFree86-dirs>=${_USE_XFREE86_DIRS}:../../misc/XFree86-dirs

.  for dir in ${XFREE86_DIRS}
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/${dir:S|/|\\/|g}$$/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm ${dir:S|/|\\/|g}$$/ \
				{ print "@comment in XFree86-dirs: "$$0; next; }
.  endfor
.endif

.endif			# !defined(DIRS_XFREE86_MK)
