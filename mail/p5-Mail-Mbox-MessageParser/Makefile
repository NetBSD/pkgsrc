# $NetBSD: Makefile,v 1.2 2004/06/23 15:34:07 snj Exp $

DISTNAME=	Mail-Mbox-MessageParser-1.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dcoppit/Mail-Mbox-MessageParser/
COMMENT=	Perl5 module for parsing mail messages

DEPENDS+=	p5-FileHandle-Unget-[0-9]*:../../devel/p5-FileHandle-Unget
DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/Mbox/MessageParser/.packlist

SETTINGS+=	INSTALLDIRS=site
# XXX: might need adaptation if the programs are not
# in the base system
SETTINGS+=	BZIP=/usr/bin/bzip2
SETTINGS+=	BZIP2=/usr/bin/bzip2
SETTINGS+=	DIFF=/usr/bin/diff
SETTINGS+=	GREP=${GREP}
SETTINGS+=	GZIP=${GZIP_CMD}
SETTINGS+=	TZIP=

MAKE_PARAMS+=	${SETTINGS}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
