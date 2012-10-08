# $NetBSD: Makefile,v 1.14 2012/10/08 12:19:31 asau Exp $

DISTNAME=	sigrot_1.2-1
PKGNAME=	sigrot-1.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/sigrot/}

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://packages.debian.org/oldstable/mail/sigrot
COMMENT=	Signature file rotation program

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/sigrot
EGDIR=		${PREFIX}/share/examples/sigrot

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CC} sigrot.c -o sigrot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sigrot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sigrot.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/copyright ${DESTDIR}${DOCDIR}/COPYRIGHT
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}/INSTALL
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/prefix ${DESTDIR}${EGDIR}/prefix
	${INSTALL_DATA} ${WRKSRC}/examples/sig_archive ${DESTDIR}${EGDIR}/sig_archive
	${INSTALL_DATA} ${WRKSRC}/examples/suffix ${DESTDIR}${EGDIR}/suffix

.include "../../mk/bsd.pkg.mk"
