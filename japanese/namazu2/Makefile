# $NetBSD: Makefile,v 1.9 2001/11/27 14:46:22 taca Exp $
# FreeBSD Id: ports/japanese/namazu2/Makefile,v 1.16 2000/10/26 20:56:25 knu Exp

DISTNAME=	namazu-2.0.8
CATEGORIES=	japanese textproc www
MASTER_SITES=	ftp://ftp.namazu.org/namazu/stable/ \
		http://www.namazu.org/stable/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.namazu.org/index.html.en
COMMENT=	Full-text search system intended for easy use

DEPENDS+=	p5-File-MMagic>=1.09:../../misc/p5-File-MMagic
DEPENDS+=	p5-Text-Kakasi>=1.04:../../japanese/p5-Text-Kakasi
DEPENDS+=	p5-nkf>=1.7:../../japanese/p5-nkf
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

USE_BUILDLINK_ONLY=	# defined
USE_PERL5=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

CONFLICTS+=	namazu-[0-9]*

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
	@${TEST} -d ${LOCALBASE}/etc/namazu || ${INSTALL_DATA_DIR} ${LOCALBASE}/etc/namazu
	@${SH} ${WRKDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
