# $NetBSD: Makefile,v 1.4 2010/08/21 16:33:26 seb Exp $

DISTNAME=	Config-Find-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5cf
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/config-inifiles/
#HOMEPAGE=	http://search.cpan.org/dist/Config-Find/
COMMENT=	Perl module for finding configuration files in the native OS fashion

DEPENDS+=	p5-File-Which>=0.05:../../devel/p5-File-Which
DEPENDS+=	p5-File-HomeDir>=0.80:../../devel/p5-File-HomeDir

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Config/Find/.packlist

post-extract:
	cd ${WRKSRC} && chmod -x lib/Config/Find.pm lib/Config/Find/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
