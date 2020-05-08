# $NetBSD: Makefile,v 1.29.10.1 2020/05/08 19:35:48 bsiegert Exp $

.include "../../databases/openldap/Makefile.version"

PKGNAME=	${DISTNAME:S/-/-doc-/}
CATEGORIES=	databases

MAINTAINER=	adam@NetBSD.org
COMMENT=	Lightweight Directory Access Protocol documentation

NO_CONFIGURE=	yes
NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/openldap

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/admin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/guide.html ${DESTDIR}${DOCDIR}/admin/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/admin/*.png ${DESTDIR}${DOCDIR}/admin/
	${INSTALL_DATA} ${WRKSRC}/doc/guide/images/*.gif ${DESTDIR}${DOCDIR}/images/

.include "../../mk/bsd.pkg.mk"
