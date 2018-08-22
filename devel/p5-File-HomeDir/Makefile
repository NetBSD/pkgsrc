# $NetBSD: Makefile,v 1.30 2018/08/22 09:44:01 wiz Exp $

DISTNAME=	File-HomeDir-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-HomeDir/
COMMENT=	Get the home directory for yourself or other users
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/HomeDir/.packlist

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		p5-File-Which-[0-9]*:../../devel/p5-File-Which
.if ${OPSYS} == "Darwin"
DEPENDS+=		p5-Mac-SystemDirectory>=0.04:../../devel/p5-Mac-SystemDirectory
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
