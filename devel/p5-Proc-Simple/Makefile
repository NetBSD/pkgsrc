# $NetBSD: Makefile,v 1.6 2009/07/08 14:23:06 sno Exp $
#

DISTNAME=	Proc-Simple-1.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Simple/
COMMENT=	Launch and control background processes

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Proc/Simple/.packlist

WRKSRC=		${WRKDIR}/mschilli-proc-simple-perl-54fa3ecd4a55aba3aa83d2843c13ecbe14d8291b

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
