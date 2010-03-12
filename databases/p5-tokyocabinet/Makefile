# $NetBSD: Makefile,v 1.22 2010/03/12 10:30:59 obache Exp $
#

DISTNAME=	tokyocabinet-perl-1.33
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/perldoc/perlpkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://1978th.net/tokyocabinet/perldoc/
COMMENT=	Perl binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/TokyoCabinet/.packlist

REPLACE_PERL=	*.pl

INSTALLATION_DIRS+=	share/tokyocabinet/doc/perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/perl/index.html

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
