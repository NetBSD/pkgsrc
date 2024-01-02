# $NetBSD: Makefile,v 1.1 2024/01/02 00:53:07 ryoon Exp $

DISTNAME=		enju-2.4.4pre20180629
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=mynlp/}
GITHUB_PROJECT=		enju
GITHUB_TAG=		d984a630b30b95de16f3b715277e95dc6fbe15b4

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://mynlp.is.s.u-tokyo.ac.jp/enju/
COMMENT=		Natural language parser for English based on HPSG grammar
LICENSE=		apache-2.0 # AND wordnet-3.0

USE_TOOLS+=		bison flex perl gsed
USE_LANGUAGES+=		c c++03
GNU_CONFIGURE=		yes

REPLACE_PERL+=		enju2ptb/script/*.prl

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	/bin/sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed=	enju2ptb/script/*.sed

_TOOLS_USE_PKGSRC.gsed=	yes
#TOOLS_IGNORE.gsed=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
