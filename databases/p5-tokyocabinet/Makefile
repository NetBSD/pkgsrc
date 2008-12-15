# $NetBSD: Makefile,v 1.7 2008/12/15 11:16:01 obache Exp $
#

DISTNAME=	tokyocabinet-perl-1.20
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/perldoc/
COMMENT=	Perl binding of Tokyo Cabinet

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/TokyoCabinet/.packlist

REPLACE_PERL=	*.pl

INSTALLATION_DIRS+=	share/tokyocabinet/doc/perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/perl/index.html

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.3.24
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
