# $NetBSD: Makefile,v 1.13 2019/08/11 13:22:28 wiz Exp $
#

DISTNAME=	Perlbal-1.80
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DO/DORMANDO/
USE_TOOLS+= perl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://danga.com/perlbal/
COMMENT=	Very configurable load balancer in perl
LICENSE=	${PERL5_LICENSE}
REPLACE_PERL+= lib/Perlbal.pm
REPLACE_PERL+= lib/Perlbal/*.pm
REPLACE_PERL+= lib/Perlbal/Plugin/*.pm
REPLACE_PERL+= lib/Perlbal/Test/*.pm

DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-IO-AIO>=0:../../devel/p5-IO-AIO
DEPENDS+=	p5-BSD-Resource>=0:../../devel/p5-BSD-Resource
DEPENDS+=	p5-HTTP-Date>=0:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message
DEPENDS+=	p5-Danga-Socket>=0:../../net/p5-Danga-Socket

DEPENDS+=	p5-BSD-Resource>=0:../../devel/p5-BSD-Resource
DEPENDS+=	p5-Danga-Socket>=1.44:../../net/p5-Danga-Socket
DEPENDS+=	p5-HTTP-Date>=0:../../www/p5-HTTP-Date
DEPENDS+=	p5-Sys-Syscall>=0:../../devel/p5-Sys-Syscall
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=0}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Perlbal/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
