# $NetBSD: Makefile,v 1.1.1.1 2001/01/27 02:29:24 taca Exp $
# FreeBSD Id: ports/japanese/namazu2/Makefile,v 1.16 2000/10/26 20:56:25 knu Exp

DISTNAME=	namazu-2.0.5
CATEGORIES=	japanese textproc www
MASTER_SITES=	http://www.namazu.org/stable/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.namazu.org/index.html.en

DEPENDS+=	p5-File-MMagic>=1.09:../../misc/p5-File-MMagic \
		p5-Text-Kakasi>=1.04:../../japanese/p5-Text-Kakasi \
		p5-nkf>=1.7:../../japanese/p5-nkf
.if !defined(WITH_CHASEN) || ${WITH_CHASEN} != NO
DEPENDS+=	p5-Text-ChaSen>=1.0:../../japanese/p5-Text-ChaSen
.endif

CONFIGURE_ARGS+=	--localstatedir=${LOCALBASE}/libdata \
			--libexecdir=${LOCALBASE}/libexec/cgi-bin
.if defined(WITH_CHASEN) && ${WITH_CHASEN} == NO
CONFIGURE_ARGS+=	-without-chasen
.else
CONFIGURE_ARGS+=	-with-chasen
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

USE_LIBINTL=		# defined
USE_PERL5=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

CONFLICTS+=	namazu-*

post-build:
	@for FILE in \
		${PKGDIR}/DEINSTALL	\
		${PKGDIR}/INSTALL;	\
	do \
		${SED}	-e 's|@CONFDIR@|${LOCALBASE}/etc/namazu|g' \
			-e 's|@DATADIR@|${LOCALBASE}/libdata/namazu|g' \
			-e 's|@EXAMPLEDIR@|${LOCALBASE}/share/namazu|g' \
			< $${FILE} > ${WRKDIR}/`basename $${FILE}`; \
	done

post-install:
	@${TEST} -d ${LOCALBASE}/etc/namazu || ${MKDIR} ${LOCALBASE}/etc/namazu
	@${SH} ${WRKDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
