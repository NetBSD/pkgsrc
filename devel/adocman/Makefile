# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 10:14:42 jmmv Exp $
#

DISTNAME=	adocman-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sitedocs/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://sitedocs.sourceforge.net/
COMMENT=	DocManager operation automation tool

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Crypt-SSLeay>=0.47:../../security/p5-SSLeay

USE_BUILDLINK2=	YES
USE_PERL5=	YES
NO_BUILD=	YES

REPLACE_PERL=	${WRKSRC}/adocman ${WRKSRC}/xml_export

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/adocman ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xml_export ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${PERL5_SITEARCH}/Alexandria
.for f in Client.pm Docman.pm
	${INSTALL_SCRIPT} ${WRKSRC}/Alexandria/$f ${PERL5_SITEARCH}/Alexandria
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/adocman
.for f in LICENSE README TODO adocman.html xml_export.html
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/html/adocman
.endfor
.undef f

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
