# $NetBSD: Makefile,v 1.67 2004/01/27 00:53:12 heinz Exp $
# FreeBSD Id: Makefile,v 1.30 1997/12/14 02:03:53 asami Exp

DISTNAME=	emacs-21.3
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	GNU editing macros (editor)

CONFLICTS=	mule-[0-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-toolkit=athena
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}

.include "../../graphics/xpm/buildlink2.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink2.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink2.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink2.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink2.mk"
CONFIGURE_ARGS+=	--with-png

.if defined(EMACS_USE_XAW3D) && !empty(EMACS_USE_XAW3D:M[Yy][Ee][Ss])
.include "../../x11/Xaw3d/buildlink2.mk"
.endif

.include "../../mk/bsd.prefs.mk"

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

INFO_FILES=	ada-mode autotype ccmode cl dired-x ebrowse ediff efaq emacs
INFO_FILES+=	emacs-mime eshell eudc forms gnus idlwave message mh-e pcl-cvs
INFO_FILES+=	reftex sc speedbar vip viper widget woman

REPLACE_PERL=	lib-src/grep-changelog

post-extract:
	${CP} ${FILESDIR}/site-init.el ${WRKSRC}/lisp

pre-install:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/emacs

.include "../../mk/bsd.pkg.mk"
