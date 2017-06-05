# $NetBSD: Makefile,v 1.25 2017/06/05 14:24:06 ryoon Exp $

DISTNAME=	Mail-Mbox-MessageParser-1.5105
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-Mbox-MessageParser/
COMMENT=	Perl5 module for parsing mail messages
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-FileHandle-Unget-[0-9]*:../../devel/p5-FileHandle-Unget
DEPENDS+=	lzip>=0:../../archivers/lzip

#DEPENDS+=	{perl>=5.10,p5-Storable-[0-9]*}:../../devel/p5-Storable

BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

PERL5_PACKLIST=		auto/Mail/Mbox/MessageParser/.packlist

USE_TOOLS+=	grep gzip

SETTINGS+=	INSTALLDIRS=site
# XXX: might need adaptation if the programs are not
# in the base system
SETTINGS+=	BZIP=/usr/bin/bzip2
SETTINGS+=	BZIP2=/usr/bin/bzip2
SETTINGS+=	DIFF=/usr/bin/diff
SETTINGS+=	XZ=/usr/bin/xz
SETTINGS+=	CAT=/bin/cat
SETTINGS+=	GZIP=${GZIP_CMD}

MAKE_PARAMS+=	--skipdeps ${SETTINGS}
MAKE_PARAMS+=	</dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
