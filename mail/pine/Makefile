# $NetBSD: Makefile,v 1.65 2002/12/14 04:34:49 hubertf Exp $
# FreeBSD Id: Makefile,v 1.21 1997/03/26 02:12:07 ache Exp
#

DISTNAME=       pine4.44
PKGNAME=        pine-4.44
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Program for Internet News and E-mail

LICENSE=	pine-license

BUILD_DEFS+=	PINE_USE_LDAP

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=	# defined

.if defined(PINE_USE_LDAP) && (${PINE_USE_LDAP} == "YES")
.  include "../../databases/openldap/buildlink2.mk"
LDAPCFLAGS=    LDAPCFLAGS="-DENABLE_LDAP"
LDAPLIBS=      LDAPLIBS="-lldap -llber"
.endif

pre-patch:
	# Make sure the imap lib that comes with pine isn't
	# used (see http://www.securityfocus.com/advisories/2646)
	${RM} -fr ${WRKSRC}/imap

do-configure:
	${CP} -f ${WRKSRC}/pine/osdep/os-${BUILDFILE}.h ${WRKSRC}/pine/osdep/os-${BUILDFILE}.h.orig
	${SED} \
		-e 's@/usr/local/lib/@${PREFIX}/etc/@' \
		-e 's@DEFAULT_DEBUG.*2@DEFAULT_DEBUG 0@' \
		<${WRKSRC}/pine/osdep/os-${BUILDFILE}.h.orig >${WRKSRC}/pine/osdep/os-${BUILDFILE}.h
	@${RM} -rf ${WRKSRC}/pico
	@${LN} -sf ${BUILDLINK_DIR}/include/pico ${WRKSRC}/pico

do-build:
	cd ${WRKSRC} && ./build ${BUILDNAME} ${LDAPCFLAGS} ${LDAPLIBS}	\
		PREFIX=${PREFIX}					\
		CC="${BUILDLINK_CC} ${CFLAGS} ${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpdump ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rpload ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pine
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.pgp.sample ${PREFIX}/share/examples/pine/dot.pinerc.pgp
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
	( ${ECHO} '# (This file is not part of the pine distribution! - HF)' ; \
	  ${PREFIX}/bin/pine -conf ) | ${SED} \
	    -e 's|^\(use-only-domain-name\)=.*$$|\1=No|g' \
	    -e 's|^\(feature-list\)=.*$$|\1=enable-mail-check-cue,enable-suspend,expanded-view-of-addressbooks,include-header-in-reply,include-text-in-reply,show-selected-in-boldface,signature-at-bottom|g' \
	    -e 's|^\(sort-key\)=.*$$|\1=Arrival/Reverse|g' \
	    >${PREFIX}/share/examples/pine/pine.conf
	${INSTALL_DATA}	${FILESDIR}/pine.conf.fixed ${PREFIX}/share/examples/pine/
	@[ -f ${PREFIX}/etc/pine.conf ] || ${CP} ${PREFIX}/share/examples/pine/pine.conf ${PREFIX}/etc/
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib
	${INSTALL_DATA_DIR} ${PREFIX}/share/pine/contrib/utils
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/pine/
	${INSTALL_DATA} ${WRKSRC}/contrib/krb5-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/ldap-setup ${PREFIX}/share/pine/contrib
	${INSTALL_DATA} ${WRKSRC}/contrib/utils/* ${PREFIX}/share/pine/contrib/utils
	${CHMOD} +x ${PREFIX}/share/pine/contrib/utils/*.sh

.include "../../editors/pico/buildlink2.mk"
.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "SunOS"
BUILDNAME= so5
BUILDFILE= sol
.elif ${OPSYS} == "Linux"
BUILDNAME= lrh
BUILDFILE= lnx
.elif ${OPSYS} == "Darwin"
BUILDNAME= osx
BUILDFILE= osx
.else
BUILDNAME= neb
BUILDFILE= neb
.endif
