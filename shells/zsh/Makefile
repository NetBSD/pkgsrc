# $NetBSD: Makefile,v 1.31 2001/12/02 16:42:00 wiz Exp $

DISTNAME=       zsh-4.0.4
CATEGORIES=	shells
MASTER_SITES=   ftp://ftp.rge.com/pub/shells/zsh/ \
		ftp://sunsite.auc.dk/pub/unix/shells/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		ftp://ftp.net.lut.ac.uk/zsh/ \
		ftp://ftp.zsh.org/zsh/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://sunsite.dk/zsh/
COMMENT=	The Z shell

GNU_CONFIGURE=	yes
INFO_FILES=	zsh.info

.include "../../mk/bsd.prefs.mk"

.if defined(ZSH_STATIC)
CONFIGURE_ARGS+=--disable-dynamic
LDFLAGS+=	-static
.else
.if ${OPSYS} == "SunOS"
PLIST_SRC=	${PKGDIR}/PLIST.dynamic ${PKGDIR}/PLIST
.else
LDFLAGS+=	-Wl,-R${PREFIX}/lib/zsh
PLIST_SRC=	${PKGDIR}/PLIST.shlibs ${PKGDIR}/PLIST.dynamic ${PKGDIR}/PLIST
.endif
.endif

.undef MANZ

post-install:
	@cd ${WRKSRC}/Doc; ${MAKE} install.info
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zsh
	@cd ${WRKSRC}/Etc; ${INSTALL_DATA} BUGS FAQ FEATURES NEWS	\
		${PREFIX}/share/doc/zsh
	${TOUCH} /etc/shells
	${CP} /etc/shells /etc/shells.bak
	(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak || ${TRUE}; ${ECHO} ${PREFIX}/bin/zsh) >/etc/shells
	${RM} /etc/shells.bak

.include "../../mk/bsd.pkg.mk"
