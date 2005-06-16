# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:41 jlam Exp $

DISTNAME=	bnc2.8.6
PKGNAME=	${DISTNAME:S/bnc/&-/}
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.gotbnc.com/files/ \
		ftp://ftp.ircadmin.net/bnc/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.gotbnc.com/
COMMENT=	Simple IRC relay proxy with support for virtual hosting

DEPENDS+=	dialog-[0-9]*:../../misc/dialog

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/bncsetup ${WRKSRC}/bncsetup.orig
	${SED}	-e "s|./mkpasswd|${PREFIX}/bin/bncmkpasswd|g"		\
		-e "s|dialog --|${LOCALBASE}/bin/dialog --|g"		\
		${WRKSRC}/bncsetup.orig > ${WRKSRC}/bncsetup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkpasswd ${PREFIX}/bin/bncmkpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/bncchk ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncsetup ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bnc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bnc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bnc
	${INSTALL_DATA} ${WRKSRC}/example.conf				\
		${PREFIX}/share/examples/bnc/bnc.conf

.include "../../mk/bsd.pkg.mk"
