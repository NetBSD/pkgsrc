# $NetBSD: Makefile,v 1.14 2022/06/28 11:31:08 wiz Exp $
#

DISTNAME=	docx2txt-1.2
PKGREVISION=	10
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docx2txt/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://docx2txt.sourceforge.net/
COMMENT=	Convert Microsoft .docx documents to simple text files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run unzip:run
REPLACE_PERL=	docx2txt.pl

BINDIR=		${PREFIX}/bin
EGDIR=		${PREFIX}/share/doc/docx2txt
CONF_FILES=	${EGDIR}/docx2txt.config ${PKG_SYSCONFDIR}/docx2txt.config

SUBST_CLASSES+=		fix-etc
SUBST_STAGE.fix-etc=	pre-configure
SUBST_MESSAGE.fix-etc=	Fixing /etc path.
SUBST_FILES.fix-etc=	*.pl README
SUBST_SED.fix-etc=	-e 's,"/etc,"${PKG_SYSCONFDIR},g'
SUBST_SED.fix-etc+=	-e 's, /etc , ${PKG_SYSCONFDIR} ,g'

SUBST_CLASSES+=		unzip
SUBST_STAGE.unzip=	pre-configure
SUBST_MESSAGE.unzip=	Hardcoding unzip path
SUBST_FILES.unzip=	*.pl *.config
SUBST_SED.unzip=	-e 's,/usr/bin/unzip,${TOOLS_PATH.unzip},'
SUBST_NOOP_OK.unzip=	yes # TOOLS_PATH.unzip may actually be /usr/bin/unzip

SUBST_CLASSES+=		suffix
SUBST_STAGE.suffix=	pre-configure
SUBST_MESSAGE.suffix=	removing .pl suffix
SUBST_FILES.suffix=	README
SUBST_SED.suffix=	-e 's,docx2txt.pl,docx2txt,'



do-build:
	mv ${WRKSRC}/docx2txt.pl ${WRKSRC}/docx2txt

do-install:
	${INSTALL_PROGRAM_DIR}				${DESTDIR}${BINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/docx2txt		${DESTDIR}${BINDIR}
	${INSTALL_DATA_DIR}				${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/docx2txt.config	${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README		${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
