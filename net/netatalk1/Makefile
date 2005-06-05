# $NetBSD: Makefile,v 1.6 2005/06/05 23:40:56 taca Exp $

DISTNAME=	netatalk-1.6.4a
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/} \
		http://me.in-berlin.de/~jroger/netatalk/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl
USE_LIBTOOL=		YES

USE_PKGINSTALL=		YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

RCD_SCRIPTS=	atalkd afpd papd timelord

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-netbsd \
			--enable-timelord \
			--with-did=last \
			--with-tcp-wrappers \
			--sbindir=${PREFIX}/libexec/netatalk \
			--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${VARBASE}/netatalk \
			--with-nls-dir=${PREFIX}/share/netatalk/nls \
			--with-uams-path=${PREFIX}/libexec/netatalk/uams

#CONFIGURE_ARGS+=	--with-flock-locks	# broken
#CONFIGURE_ARGS+=	--with-bdb=${PREFIX}	# still some known issues

.include "options.mk"

post-patch:
	${MV} ${WRKSRC}/etc/psf/etc2ps.sh ${WRKSRC}/etc/psf/etc2ps.sh.tmp
	${SED} -e "s,^\(DVIPS=\)\(/usr/local/tex\)\(/bin\),\1${PREFIX}\3," \
		< ${WRKSRC}/etc/psf/etc2ps.sh.tmp > ${WRKSRC}/etc/psf/etc2ps.sh

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/psffilters
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/netatalk
.for FILE in atalkd.conf netatalk.conf papd.conf AppleVolumes.default \
		AppleVolumes.system afpd.conf
	@-( cd ${WRKSRC}/config; ${MAKE_PROGRAM} ${FILE} )
	${INSTALL_DATA} ${WRKSRC}/config/${FILE} \
					${PREFIX}/share/examples/netatalk/
.endfor

#.include "../../databases/db3/buildlink3.mk"
.include "../../devel/rx/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
