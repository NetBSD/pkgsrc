# $NetBSD: Makefile,v 1.5 2010/09/06 10:55:01 wiz Exp $
#

VERS=			1.02a
DISTNAME=		MIME-Base32-${VERS}
PKGNAME=		p5-MIME-Base32-${VERS}
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/MIME-Base32/
COMMENT=		Perl5 module for Base32 encoding
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

# needed for 1.02a
WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}

PERL5_PACKLIST=		auto/MIME/Base32/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
