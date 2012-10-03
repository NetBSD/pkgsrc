# $NetBSD: Makefile,v 1.4 2012/10/03 21:55:32 wiz Exp $
#

DISTNAME=		Proc-WaitStat-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Proc-WaitStat/
COMMENT=		Perl5 extension to interpret wait status values
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-IPC-Signal-[0-9]*:../../devel/p5-IPC-Signal

PERL5_PACKLIST=		auto/Proc/WaitStat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
