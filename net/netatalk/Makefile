# $NetBSD: Makefile,v 1.14 2002/05/25 12:55:24 markd Exp $

DISTNAME=       netatalk-1.5.3.1
CATEGORIES=     net print
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=netatalk/} \
		http://me.in-berlin.de/~jroger/netatalk/ \

GNU_CONFIGURE=  yes
USE_GMAKE=      yes
USE_PERL5=      yes
#USE_LIBTOOL=    yes
#LIBTOOL_OVERRIDE=${WRKSRC}/libtool

.include "../../mk/bsd.prefs.mk"
CONFIGURE_ARGS+=        --with-tcp-wrappers --with-flock-locks \
			--enable-timelord \
                        --localstatedir=/var/netatalk \
                        --sbindir=${PREFIX}/libexec/netatalk \
                        --with-uams-path=${PREFIX}/libexec/netatalk/uams \
			--sysconfdir=${PKG_SYSCONFDIR} \
			--enable-netbsd

MAINTAINER=     markd@netbsd.org
HOMEPAGE=       http://sourceforge.net/projects/netatalk/
COMMENT=        Netatalk appletalk file and print services

CONFLICTS=      netatalk-asun-[0-9]*
CONFLICTS+=     netatalk-umich-[0-9]*

MESSAGE_SUBST+=	PREFIX=${PREFIX}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/netatalk
.for FILE in atalkd.conf netatalk.conf papd.conf AppleVolumes.default \
		AppleVolumes.system afpd.conf
	@-( cd ${WRKSRC}/config; gmake ${FILE} )
	${INSTALL_DATA} ${WRKSRC}/config/${FILE} \
					${PREFIX}/share/examples/netatalk/
.endfor

.include "../../mk/bsd.pkg.mk"
