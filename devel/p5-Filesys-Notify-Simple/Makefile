# $NetBSD: Makefile,v 1.2 2010/04/10 08:28:57 seb Exp $
#

DISTNAME=		Filesys-Notify-Simple-0.06
PKGNAME=		p5-${DISTNAME}
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
