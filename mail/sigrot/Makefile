# $NetBSD: Makefile,v 1.4 2004/01/20 12:19:44 agc Exp $

DISTNAME=	sigrot_1.2-1
PKGNAME=	sigrot-1.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/sigrot/}

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://packages.debian.org/stable/mail/sigrot.html
COMMENT=	Signature file rotation program

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

DOCDIR=		${PREFIX}/share/doc/sigrot
EGDIR=		${PREFIX}/share/examples/sigrot

do-build:
	cd ${WRKSRC} && ${CC} sigrot.c -o sigrot

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sigrot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sigrot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/copyright ${DOCDIR}/COPYRIGHT
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}/INSTALL
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/prefix ${EGDIR}/prefix
	${INSTALL_DATA} ${WRKSRC}/examples/sig_archive ${EGDIR}/sig_archive
	${INSTALL_DATA} ${WRKSRC}/examples/suffix ${EGDIR}/suffix

.include "../../mk/bsd.pkg.mk"
