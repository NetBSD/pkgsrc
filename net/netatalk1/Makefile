# $NetBSD: Makefile,v 1.14 2007/12/31 05:41:36 taca Exp $

DISTNAME=	netatalk-1.6.4a
PKGREVISION=	4
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services

DEPENDS=	rc>=1.5:../../shells/rc

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
USE_LIBTOOL=	YES
USE_OLD_DES_API=YES
BUILDLINK_TRANSFORM+=	l:db-4.2:db4

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

RCD_SCRIPTS=	atalkd afpd papd timelord

.for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.$f=	# avoid automatic handling
.endfor

BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-netbsd \
			--enable-timelord \
			--with-did=last \
			--with-tcp-wrappers \
			--sbindir=${PREFIX}/libexec/netatalk \
			--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--localstatedir=${VARBASE}/netatalk \
			--with-nls-dir=${PREFIX}/share/netatalk/nls \
			--with-uams-path=${PREFIX}/libexec/netatalk/uams \
			--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

#CONFIGURE_ARGS+=	--with-flock-locks	# broken
#CONFIGURE_ARGS+=	--with-bdb=${PREFIX}	# still some known issues

.for cf in AppleVolumes.default AppleVolumes.system afpd.conf \
	atalkd.conf netatalk.conf papd.conf
CONF_FILES+=		${PREFIX}/share/examples/netatalk/${cf} ${PKG_SYSCONFDIR}/${cf}
.endfor

SUBST_CLASSES+=	paths
SUBST_FILES.paths+=	${WRKSRC}/etc/psf/etc2ps.sh
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.paths=	pre-configure

SUBST_CLASSES+=		rc
SUBST_FILES.rc=		${WRKSRC}/bin/afile/acleandir.rc
SUBST_SED.rc+=		-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.rc=		pre-configure

.include "options.mk"

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/psffilters
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/netatalk
.for file in atalkd.conf netatalk.conf papd.conf AppleVolumes.default \
		AppleVolumes.system afpd.conf
	( cd ${WRKSRC}/config; ${MAKE_PROGRAM} ${file} || ${TRUE} )
	${INSTALL_DATA} ${WRKSRC}/config/${file} \
					${PREFIX}/share/examples/netatalk/
.endfor

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
