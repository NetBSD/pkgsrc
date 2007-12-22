# $NetBSD: Makefile,v 1.2 2007/12/22 01:07:01 joerg Exp $
#

PKGNAME=		scmgit-docs-${GIT_VERSION}
COMMENT=		GIT Tree History Storage Tool (documentation)

DISTINFO_FILE=		${.CURDIR}/../scmgit-base/distinfo

BUILD_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=		xmlto-[0-9]*:../../textproc/xmlto

BUILD_TARGET=		doc

USE_LANGUAGES=		# none
INSTALL_TARGET=		install-doc

.include "../../mk/bsd.fast.prefs.mk"

.for d in asciidoc docbook-xsl
GITDOCDEP.${d}=	${${${PKG_INFO} -E ${d} || echo:L:sh}:L:C/[^[0-9]]*/ /g:[1..3]:ts.}
.endfor

.if !empty(GITDOCDEP.asciidoc:M[8]*)
MAKE_ENV+=	AsciiDoc8=YesPlease
.endif

.if !empty(GITDOCDEP.docbook-xsl:M1.7[2-9]*)
MAKE_ENV+=	DOCBOOK_XSL_172=YesPlease
.endif

.include "${.CURDIR}/../scmgit/Makefile.common"

.include "../../mk/bsd.pkg.mk"
