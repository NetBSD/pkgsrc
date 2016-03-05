# $NetBSD: Makefile,v 1.27 2016/03/05 11:28:47 jperkin Exp $

DISTNAME=	dk-milter-1.0.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dk-milter/
COMMENT=	Open source DomainKeys filter software from Sendmail, Inc
LICENSE=	sendmail-open-source-license

MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dk-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-patch
SUBST_FILES.libs=	site.config.m4.dist dk-filter/Makefile.m4 \
			devtools/M4/header.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS:Q} ${PTHREAD_LIBS:Q}|g'
.if ${OPSYS} == SunOS
SUBST_SED.libs+=        -e 's|-lrt|-lrt -lresolv|g'
.endif
SUBST_MESSAGE.libs=	Fixing makefile references.

# Rename dk-filter to dk-milter.
# tv@ has done this when importing the original dk-milter package from
# pkgsrc-wip to pkgsrc, hence we continue this tradition.
SUBST_CLASSES+=		rename
SUBST_STAGE.rename=	post-build
SUBST_FILES.rename=	dk-filter/dk-filter.8
SUBST_SED.rename=	-e 's|dk-filter|dk-milter|g'
SUBST_MESSAGE.rename=	Renaming dk-filter to dk-milter

SUBST_CLASSES+=		gentxt
SUBST_STAGE.gentxt=	post-build
SUBST_FILES.gentxt=	INSTALL
SUBST_SED.gentxt=	-e '/Run the script/s,gentxt.csh,dk-milter-gentxt.csh,'
SUBST_SED.gentxt+=	-e '/DNS system/s,published.,published (dk-milter-gentxt.csh is in ${PREFIX}/sbin).,'
SUBST_SED.gentxt+=	-e 's/dk-filter/dk-milter/g'
SUBST_MESSAGE.gentxt=	Modify PATH and name of gentxt.csh

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man8 sbin share/doc/dk-milter/libdk

pre-configure:
	mv ${WRKSRC}/site.config.m4.dist ${WRKSRC}/devtools/Site/site.config.m4

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	cd ${WRKSRC}/obj.`uname -s`.`uname -r`.`uname -m`; \
	${INSTALL_PROGRAM} dk-filter/dk-filter ${DESTDIR}${PREFIX}/sbin/dk-milter; \
	${INSTALL_SCRIPT} ${WRKSRC}/dk-filter/gentxt.csh ${DESTDIR}${PREFIX}/sbin/dk-milter-gentxt.csh; \
	${INSTALL_LIB} libdk/libdk.a ${DESTDIR}${PREFIX}/lib
# man pages
	${INSTALL_MAN} ${WRKSRC}/dk-filter/dk-filter.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/dk-milter.8
# documents in source
	cd ${WRKSRC} ;\
	for f in FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES rfc4870.txt; do\
	  ${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/dk-milter ;\
	done 
	cd ${WRKSRC}/libdk/docs; for file in *.html; do \
	${INSTALL_DATA} $$file ${DESTDIR}${PREFIX}/share/doc/dk-milter/libdk; done

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
