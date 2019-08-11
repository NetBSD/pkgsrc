# $NetBSD: Makefile,v 1.42 2019/08/11 13:23:23 wiz Exp $

DISTNAME=	docbook-dsssl-1.79
PKGNAME=	dsssl-docbook-modular-1.79
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docbook/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} docbook-dsssl-doc-1.79${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docbook.sourceforge.net/
COMMENT=	DSSSL stylesheets for the DocBook DTD

DEPENDS+=	docbook>=4.0:../../textproc/docbook

USE_LANGUAGES=	# empty
USE_TOOLS+=	perl:run

INSTDIR=	${PREFIX}/share/sgml/docbook/dsssl/modular

SGML_CATALOGS=	${PREFIX}/share/sgml/docbook/dsssl/modular/catalog

REPLACE_PERL+=	bin/collateindex.pl
REPLACE_PERL+=	common/cs-hack.pl
REPLACE_PERL+=	common/dbl10n.pl

do-build:
	@${RM} -rf ${WRKSRC}/docsrc

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${INSTDIR}

do-install:
	@${CP} -rp ${WRKSRC}/* ${DESTDIR}${INSTDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${INSTDIR}
	${CHMOD} ${BINMODE} ${DESTDIR}${INSTDIR}/bin/collateindex.pl

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
