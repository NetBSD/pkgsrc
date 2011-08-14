# $NetBSD: Makefile,v 1.40 2011/08/14 14:14:40 obache Exp $
#

DISTNAME=	clive-2.3.1.1
PKGREVISION=	1
CATEGORIES=	net multimedia www
MASTER_SITES=	http://clive.googlecode.com/files/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts
LICENSE=	gnu-gpl-v3

DEPENDS+=	quvi>=0.2.17:../../net/quvi
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	p5-JSON-XS>=2.3:../../converters/p5-JSON-XS
DEPENDS+=	p5-Getopt-ArgvFile>=1.11:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-version>=0.77:../../devel/p5-version

PKG_DESTDIR_SUPPORT=	user-destdir

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
