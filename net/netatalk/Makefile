# $NetBSD: Makefile,v 1.13.2.1 2002/06/23 18:55:57 jlam Exp $

DISTNAME=	netatalk-1.5.3.1
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/} \
		http://me.in-berlin.de/~jroger/netatalk/

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/netatalk/
COMMENT=	Netatalk appletalk file and print services

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-tcp-wrappers --with-flock-locks \
			--enable-timelord \
			--localstatedir=/var/netatalk \
			--sbindir=${PREFIX}/libexec/netatalk \
			--with-uams-path=${PREFIX}/libexec/netatalk/uams \
			--sysconfdir=${PKG_SYSCONFDIR} \
			--enable-netbsd

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/psffilters
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/netatalk
.for FILE in atalkd.conf netatalk.conf papd.conf AppleVolumes.default \
		AppleVolumes.system afpd.conf
	@-( cd ${WRKSRC}/config; ${MAKE_PROGRAM} ${FILE} )
	${INSTALL_DATA} ${WRKSRC}/config/${FILE} \
					${PREFIX}/share/examples/netatalk/
.endfor

.include "../../mk/bsd.pkg.mk"
