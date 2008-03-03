# $NetBSD: Makefile,v 1.16 2008/03/03 02:19:51 jlam Exp $

DISTNAME=	bnc2.9.4
PKGNAME=	${DISTNAME:S/bnc/&-/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.gotbnc.com/files/ \
  http://www.ircadmin.net/bnc/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gotbnc.com/
COMMENT=	Simple IRC relay proxy with support for virtual hosting

DEPENDS+=	dialog-[0-9]*:../../misc/dialog

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/bncsetup ${WRKSRC}/bncsetup.orig
	${SED}	-e "s|./mkpasswd|${PREFIX}/bin/bncmkpasswd|g"		\
		-e "s|dialog --|${LOCALBASE}/bin/dialog --|g"		\
		${WRKSRC}/bncsetup.orig > ${WRKSRC}/bncsetup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkpasswd ${DESTDIR}${PREFIX}/bin/bncmkpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/bncchk ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncsetup ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/bnc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/bnc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bnc
	${INSTALL_DATA} ${WRKSRC}/example.conf				\
		${DESTDIR}${PREFIX}/share/examples/bnc/bnc.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
