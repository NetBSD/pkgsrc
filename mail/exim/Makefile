# $NetBSD: Makefile,v 1.29 2002/07/02 14:41:20 wiz Exp $

DISTNAME=	exim-4.05
CATEGORIES=	mail net
MASTER_SITES=	ftp://ftp.exim.org/pub/exim/exim4/ \
		ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/exim4/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/exim4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

USE_PERL5=	yes
INTERACTIVE_STAGE=	build # actually, needs "mail" user
                              # before configure step, see below

pre-patch:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${WRKSRC}/src/EDITME ${WRKSRC}/Local/Makefile.netbsd

pre-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    < ${WRKSRC}/Local/Makefile.netbsd \
	    > ${WRKSRC}/Local/Makefile

pre-build:
	@(if ! ${ID} mail 2>/dev/null >/dev/null; then\
		${ECHO} "!! ";\
		${ECHO} "!! Use vipw to add the following to master.passwd:";\
		${ECHO} "!! ";\
		${ECHO} "!!  mail:*:8:6::0:0:Electronic Mail:/var/mail:/sbin/nologin";\
		${ECHO} "!! ";\
		${FALSE};\
	fi)

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/exim
	${INSTALL_DATA_DIR} /var/log/exim
	${CHMOD} 750 /var/log/exim
	strip ${WRKSRC}/build-*/exim
	strip ${WRKSRC}/build-*/exim_dbmbuild
	strip ${WRKSRC}/build-*/exim_tidydb
	strip ${WRKSRC}/build-*/exim_fixdb
	strip ${WRKSRC}/build-*/exim_dumpdb
	strip ${WRKSRC}/build-*/exim_lock

post-install:
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim \
	    > ${PREFIX}/etc/rc.d/exim
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/exim_newaliases \
	    > ${PREFIX}/sbin/exim_newaliases
	${CHMOD} ugo+x ${PREFIX}/sbin/exim_newaliases
	${SED} -e 's:@PREFIX@:${PREFIX}:' \
	    ${FILESDIR}/mailer.conf.exim \
	    > ${PREFIX}/etc/exim/mailer.conf.exim

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
