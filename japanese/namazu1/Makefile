# $NetBSD: Makefile,v 1.8 2001/11/29 01:12:37 hubertf Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/03/31 11:52:07 flathill Exp $

DISTNAME=	namazu-1.3.0.11
PKGREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.namazu.org/stable/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.namazu.org/index.html.en
COMMENT=	Namazu is a search engine software intended for easy use

DEPENDS=	kakasi>=2.3.1:../../japanese/kakasi
DEPENDS+=	nkf-1.7:../../japanese/nkf
.if !defined(WITH_CHASEN) || ${WITH_CHASEN} != NO
DEPENDS+=	p5-Text-ChaSen>=1.0:../../japanese/p5-Text-ChaSen
.endif

CONFIGURE_ARGS+=	--with-cgi-dir=${LOCALBASE}/libexec/cgi-bin
.if defined(WITH_CHASEN) && ${WITH_CHASEN} == NO
CONFIGURE_ARGS+=	-without-chasen
.else
CONFIGURE_ARGS+=	-with-chasen
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

USE_PERL5=	yes
GNU_CONFIGURE=	yes

CONFLICTS+=	namazu-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/src
CONTRIBDIR=	${WRKDIR}/${DISTNAME}/contrib

CONFDIR=	${LOCALBASE}/etc/namazu
DOCDIR=		${LOCALBASE}/share/namazu/doc
INDEXDIR=	${LOCALBASE}/libdata/namazu

post-build:
	@${SED} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		< ${CONTRIBDIR}/bnamazu > ${WRKDIR}/bnamazu
	@for FILE in \
		${PKGDIR}/DEINSTALL	\
		${PKGDIR}/INSTALL;	\
	do \
		${SED}	-e 's|@CONFDIR@|${CONFDIR}|g' \
			-e 's|@INDEXDIR@|${INDEXDIR}|g' \
			-e 's|@DOCDIR@|${DOCDIR}|g' \
			< $${FILE} > ${WRKDIR}/`basename $${FILE}`; \
	done

post-install:
	@cd ${WRKSRC}; ${MAKE} install_cgi
	@${INSTALL_SCRIPT} ${WRKDIR}/bnamazu ${LOCALBASE}/bin
	@${TEST} -d ${LOCALBASE}/etc/namazu || ${INSTALL_DATA_DIR} ${LOCALBASE}/etc/namazu
	@${SH} ${WRKDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
