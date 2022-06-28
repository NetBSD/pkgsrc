# $NetBSD: Makefile,v 1.59 2022/06/28 11:34:58 wiz Exp $

DISTNAME=	clive-2.3.3
PKGREVISION=	11
CATEGORIES=	net multimedia www
MASTER_SITES=	http://clive.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts
LICENSE=	gnu-gpl-v3

DEPENDS+=	quvi>=0.4.0:../../net/quvi
DEPENDS+=	libquvi-scripts>=0.4.0:../../net/libquvi-scripts
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	p5-JSON-XS>=2.3:../../converters/p5-JSON-XS
DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
#DEPENDS+=	{perl>=5.10.1,p5-version>=0.77}:../../devel/p5-version

PERL5_PACKLIST=		auto/clive/.packlist
INSTALLATION_DIRS=	share/examples/clive

CONF_FILES=	${PREFIX}/share/examples/clive/cliverc ${PKG_SYSCONFDIR}/cliverc

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e "s,/usr/local/share/clive/cliverc,${PKG_SYSCONFDIR}/cliverc,"
SUBST_FILES.config+=	bin/clive
SUBST_STAGE.config=	pre-build
SUBST_MESSAGE.config=	Fixing path to global config file.

post-build:
	sed "s,/usr/,${PREFIX}/," ${WRKSRC}/examples/cliverc > ${WRKSRC}/cliverc

post-install:
	${INSTALL_DATA} ${WRKSRC}/cliverc ${DESTDIR}${PREFIX}/share/examples/clive

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
