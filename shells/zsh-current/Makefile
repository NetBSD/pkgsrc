# $NetBSD: Makefile,v 1.3 2003/06/29 03:05:28 uebayasi Exp $

DISTNAME=       zsh-4.1.1
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		ftp://ftp.net.lut.ac.uk/zsh/ \
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

# Utilize Zsh's test framework.
#
.PHONY: do-test do-su-test real-su-test

do-test: do-su-test

do-su-test:
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "*** Warning: This test needs to be run as root"
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-test";					\
	action="install";						\
	${_SU_TARGET}

real-su-test:
	@${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "${_PKGSRC_IN}> Testing for ${PKGNAME}"
	@cd ${WRKSRC} && ${MAKE} check
	@cd ${WRKSRC}/Test && ${MAKE} clean

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
