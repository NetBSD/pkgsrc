# $NetBSD: Makefile,v 1.38 2019/08/11 13:18:35 wiz Exp $
#

DISTNAME=	tokyocabinet-perl-1.34
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/perldoc/perlpkg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/tokyocabinet/perldoc/
COMMENT=	Perl binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

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
