# $NetBSD: Makefile,v 1.26 2018/08/22 09:43:27 wiz Exp $
#

DISTNAME=	adocman-0.10
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sitedocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sitedocs.sourceforge.net/
COMMENT=	DocManager operation automation tool

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Crypt-SSLeay>=0.47:../../security/p5-Crypt-SSLeay

NO_BUILD=		yes
PERL5_CONFIGURE=	no
REPLACE_PERL=		adocman xml_export
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/adocman ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xml_export ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/Alexandria
	cd ${WRKSRC}/Alexandria && ${INSTALL_SCRIPT} \
		Client.pm Docman.pm \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/Alexandria
	cd ${WRKSRC} && ${INSTALL_DATA} \
		LICENSE README TODO adocman.html xml_export.html \
		${DESTDIR}${PREFIX}/share/doc/adocman

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
