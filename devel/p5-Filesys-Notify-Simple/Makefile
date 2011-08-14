# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:06 obache Exp $
#

DISTNAME=		Filesys-Notify-Simple-0.06
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Filesys-Notify-Simple/
COMMENT=		Perl5 module providing a simple and dumb file system watcher
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Filesys/Notify/Simple/.packlist

BUILD_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
