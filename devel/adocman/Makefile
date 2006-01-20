# $NetBSD: Makefile,v 1.13 2006/01/20 20:38:09 wiz Exp $
#

DISTNAME=	adocman-0.10
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sitedocs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sitedocs.sourceforge.net/
COMMENT=	DocManager operation automation tool

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Crypt-SSLeay>=0.47:../../security/p5-Crypt-SSLeay

NO_BUILD=		yes
PERL5_CONFIGURE=	no
REPLACE_PERL=		adocman xml_export

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/adocman ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xml_export ${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${PERL5_INSTALLVENDORLIB}/Alexandria
.for f in Client.pm Docman.pm
	${INSTALL_SCRIPT} ${WRKSRC}/Alexandria/${f} ${PERL5_INSTALLVENDORLIB}/Alexandria
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/adocman
.for f in LICENSE README TODO adocman.html xml_export.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/html/adocman
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
