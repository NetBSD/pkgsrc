# $NetBSD: Makefile,v 1.6 2019/07/01 22:00:10 nia Exp $

DISTNAME=	svn-bisect-1.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Infinoid/}
GITHUB_TAG=	3768ca85fb962e6380564aa5ab11853ec5720abc
GITHUB_PROJECT=	svn-bisect

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/App-SVN-Bisect
COMMENT=	Bisect SVN repositories to find a particular change
LICENSE=	artistic-2.0

DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
DEPENDS+=	p5-YAML-Syck-[0-9]*:../../textproc/p5-YAML-Syck
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All

PERL5_PACKLIST=		auto/App/SVN/Bisect/.packlist

INSTALLATION_DIRS+=	bin

post-install:
	${LN} -s ${PERL5_INSTALLVENDORBIN}/svn-bisect ${DESTDIR}${PREFIX}/bin

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
