# $NetBSD: Makefile,v 1.40 2003/06/20 05:59:02 uebayasi Exp $

DISTNAME=       zsh-4.0.7
CATEGORIES=	shells
MASTER_SITES=   ftp://sunsite.dk/pub/unix/shells/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		ftp://ftp.lysator.liu.se/pub/unix/zsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/zsh/ \
		http://www.math.technion.ac.il/pub/zsh/ \
		ftp://ftp.zsh.org/zsh/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gcw@zsh.org
HOMEPAGE=	http://sunsite.dk/zsh/
COMMENT=	The Z shell

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		zsh.info
TEXINFO_OVERRIDE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
CONFIGURE_ARGS+=--disable-dynamic
LDFLAGS+=	-static
.else
.if ${OPSYS} == "SunOS"
PLIST_SRC=	${PKGDIR}/PLIST.dynamic ${PKGDIR}/PLIST
.else
LDFLAGS+=	-Wl,${RPATH_FLAG}${PREFIX}/lib/zsh
PLIST_SRC=	${PKGDIR}/PLIST.shlibs ${PKGDIR}/PLIST.dynamic ${PKGDIR}/PLIST
.endif
.endif

.undef MANZ

PKG_SHELL=	${PREFIX}/bin/zsh

post-install:
	@cd ${WRKSRC}/Doc; ${MAKE} install.info
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zsh
	@cd ${WRKSRC}/Etc; ${INSTALL_DATA} BUGS FAQ FEATURES NEWS	\
		${PREFIX}/share/doc/zsh

test:
	@if [ `${ID} -u` != 0 ]; then					\
		${ECHO_MSG} "You must be root to run this target.";	\
	else								\
		(cd ${WRKSRC}; ${MAKE} check)				\
	fi

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
