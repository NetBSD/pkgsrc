# $NetBSD: Makefile,v 1.80.4.1 2007/12/17 21:10:22 ghen Exp $

DISTNAME=	mrtg-2.15.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://oss.oetiker.ch/mrtg/pub/ \
		http://oss.oetiker.ch/mrtg/pub/old/ \
		ftp://ftp2.cscnet.cz/pub/mirror/mrtg/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://oss.oetiker.ch/mrtg/
COMMENT=	The Multi-Router Traffic Grapher

USE_TOOLS+=	perl:run
GNU_CONFIGURE=	YES

LDFLAGS+=	-lgd -lintl -ljpeg

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-z-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-z-inc=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-png-lib=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-png-inc=${LOCALBASE}/include
.endif

REPLACE_PERL=	bin/cfgmaker bin/indexmaker bin/mrtg
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=	${EGDIR}/mrtg.conf ${PKG_SYSCONFDIR}/mrtg.conf

.include "options.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-patch
SUBST_FILES.files=	../mrtg.conf.example ../netstat2mrtg		\
			../sys2mrtg ../envstat2mrtg
SUBST_SED.files=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.files=	Fixing default configuration files.

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 ${EGDIR}
INSTALLATION_DIRS+=	share/mrtg share/doc/mrtg

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"

post-extract:
	cp ${FILESDIR}/mrtg.conf.example ${WRKDIR}
	cp ${FILESDIR}/netstat2mrtg ${WRKDIR}
	cp ${FILESDIR}/sys2mrtg ${WRKDIR}
	cp ${FILESDIR}/envstat2mrtg ${WRKDIR}

do-install:
	for FILE in ${WRKSRC}/doc/*.??*; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/mrtg; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/mrtg*.1 ${PREFIX}/${PKGMANDIR}/man1/
	for FILE in cfgmaker.1 indexmaker.1; do \
	  ${INSTALL_DATA} ${WRKSRC}/doc/$$FILE ${PREFIX}/${PKGMANDIR}/man1/mrtg$$FILE; \
	done
	for FILE in CHANGES COPYING COPYRIGHT README; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$FILE ${PREFIX}/share/doc/mrtg; \
	done
	for FILE in ${WRKSRC}/images/*.png; do \
	  ${INSTALL_DATA} $$FILE ${PREFIX}/share/mrtg; \
	done
	${INSTALL_DATA} ${WRKDIR}/mrtg.conf.example ${EGDIR}/mrtg.conf
	for FILE in netstat2mrtg sys2mrtg envstat2mrtg; do \
	  ${INSTALL_SCRIPT} ${WRKDIR}/$$FILE ${PREFIX}/libexec; \
	done
	${INSTALL_DATA_DIR} ${PERL5_INSTALLVENDORLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mrtg2/BER.pm \
	  ${WRKSRC}/lib/mrtg2/SNMP_Session.pm \
	  ${WRKSRC}/lib/mrtg2/SNMP_util.pm \
	  ${WRKSRC}/lib/mrtg2/Net_SNMP_util.pm \
	  ${WRKSRC}/lib/mrtg2/MRTG_lib.pm \
	  ${WRKSRC}/lib/mrtg2/locales_mrtg.pm \
	  ${PERL5_INSTALLVENDORLIB}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rateup ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mrtg ${PREFIX}/bin/
	for FILE in cfgmaker indexmaker; do \
	  ${INSTALL_SCRIPT} ${WRKSRC}/bin/$$FILE ${PREFIX}/bin/mrtg$$FILE; \
	done

.include "../../mk/bsd.pkg.mk"
