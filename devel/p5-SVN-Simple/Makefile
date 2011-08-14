# $NetBSD: Makefile,v 1.19 2011/08/14 12:26:34 obache Exp $

DISTNAME=	SVN-Simple-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Simple/
COMMENT=	Simple interface to the Subversion delta editor interface
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
