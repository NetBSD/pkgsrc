# $NetBSD: Makefile,v 1.10 2024/01/31 15:11:46 ryoon Exp $
#

DISTNAME=	skk-jisyo
PKGNAME=	skk-jisyo-cdb-${SKKJISYO_DATE}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=skk-dev/}
GITHUB_PROJECT=	dict
GITHUB_TAG=	00896147273037623f6416684ef586ab17297be2
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/skk-dev/dict
COMMENT=	Dictionary collection for SKK
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	tinycdb-[0-9]*:../../databases/tinycdb

USE_LANGUAGES=	# empty

SKKJISYO_DATE=	20240117

INSTALLATION_DIRS+=	${PREFIX}/share/skk

SKK_DICTS=		SKK-JISYO.L SKK-JISYO.JIS3_4

do-build:
.for dict in ${SKK_DICTS}
	LC_ALL=C ${AWK} '/^[^;]/ { \
			s = substr($$0, index($$0, " ") + 1); \
			print "+" length($$1) "," length(s) ":" $$1 "->" s; \
		} \
		END { \
			print ""; \
		}' \
		< ${WRKSRC}/${dict} | \
	${LOCALBASE}/bin/cdb -c -t - \
		${WRKSRC}/${dict}.cdb
.endfor

do-install:
.for dict in ${SKK_DICTS}
	${INSTALL_DATA} ${WRKSRC}/${dict}.cdb \
		${DESTDIR}${PREFIX}/share/skk
.endfor

.include "../../mk/bsd.pkg.mk"
