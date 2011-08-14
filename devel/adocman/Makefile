# $NetBSD: Makefile,v 1.18 2011/08/14 12:26:05 obache Exp $
#

DISTNAME=	adocman-0.10
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sitedocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sitedocs.sourceforge.net/
COMMENT=	DocManager operation automation tool

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Crypt-SSLeay>=0.47:../../security/p5-Crypt-SSLeay

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
PERL5_CONFIGURE=	no
REPLACE_PERL=		adocman xml_export

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/adocman ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/xml_export ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/Alexandria
.for f in Client.pm Docman.pm
	${INSTALL_SCRIPT} ${WRKSRC}/Alexandria/${f} \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/Alexandria
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/adocman
.for f in LICENSE README TODO adocman.html xml_export.html
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/html/adocman
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
