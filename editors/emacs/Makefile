# $NetBSD: Makefile,v 1.72 2004/04/19 15:39:34 markd Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.3
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-toolkit=athena
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}

.include "../../graphics/xpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--with-png

.include "../../mk/bsd.prefs.mk"

.if defined(EMACS_USE_XAW3D) && !empty(EMACS_USE_XAW3D:M[Yy][Ee][Ss])
.include "../../x11/Xaw3d/buildlink3.mk"
.endif

# This matches NetBSD <1.7 releases and 1.6A-1.6P, where ld is <2.13.2.1.
.if ${OPSYS} == "NetBSD" && \
    (empty(OS_VERSION:M1.[0-5]*) && \
     empty(OS_VERSION:M1.6_*) && \
     empty(OS_VERSION:M1.6) && \
     empty(OS_VERSION:M1.6.[0-9]*) && \
     empty(OS_VERSION:M1.6[A-P]*))
# If using GNU ld 2.13.2.1 or later, avoid creating combined reloc
# sections and .data reloc sections, both of which Emacs can't handle
# properly.  Analyzed by Stephen Ma.
LDFLAGS+=	-Wl,-z,nocombreloc
.endif

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3.*)
CFLAGS+=	-fno-zero-initialized-in-bss
.endif

INFO_FILES=	ada-mode autotype ccmode cl dired-x ebrowse ediff efaq emacs
INFO_FILES+=	emacs-mime eshell eudc forms gnus idlwave message mh-e pcl-cvs
INFO_FILES+=	reftex sc speedbar vip viper widget woman

REPLACE_PERL=	lib-src/grep-changelog

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp
	${CP} ${FILESDIR}/amd64.h ${WRKSRC}/src/m

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
