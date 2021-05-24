# $NetBSD: Makefile,v 1.6 2021/05/24 19:54:18 wiz Exp $

DISTNAME=	Unix-Process-1.3101
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unix-Process
COMMENT=	Perl extension to get pid info from ps(1)
#LICENSE=	"lgpl"

DEPENDS+=	p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple

PERL5_PACKLIST=		auto/Unix/Process/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
