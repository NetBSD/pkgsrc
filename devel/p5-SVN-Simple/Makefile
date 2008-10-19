# $NetBSD: Makefile,v 1.16 2008/10/19 19:18:00 he Exp $

DISTNAME=	SVN-Simple-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple interface to the Subversion delta editor interface

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-subversion>=1.0.4:../../devel/p5-subversion

PERL5_PACKLIST=		auto/SVN/Simple/Edit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
