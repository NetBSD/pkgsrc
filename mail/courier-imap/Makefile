# $NetBSD: Makefile,v 1.2 2001/08/12 18:17:15 jlam Exp $

DISTNAME=	courier-imap-1.3.8.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.inter7.com/courierimap/
COMMENT=	IMAP server for access to Maildir-style mailboxes

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
USE_PERL5=		# defined
REPLACE_PERL=		sysconftool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/courier
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/courier
CONFIGURE_ARGS+=	--sysconfdir=/etc/courier
CONFIGURE_ARGS+=	--enable-unicode
CONFIGURE_ARGS+=	--with-db=db
CONFIGURE_ARGS+=	--with-userdb=/etc/courier/userdb
CONFIGURE_ARGS+=	--disable-root-check
CONFIGURE_ENV+=		OPENSSL=${BUILDLINK_PREFIX.openssl}/bin/openssl
CONFIGURE_ENV+=		SSLCERTS=${SSLCERTS}

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.prefs.mk"

#.if defined(USE_PAM)
#.include "../../security/PAM/buildlink.mk"
#.endif

.if ${OPSYS} == "SunOS"
.include "../../databases/db/buildlink.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/db2
.endif

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		SSLCERTS=${SSLCERTS}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	cd ${WRKSRC}; for file in					\
		imap/imapd.dist.in imap/imapd-ssl.dist.in		\
		imap/pop3d.dist.in imap/pop3d-ssl.dist.in		\
		imap/mkimapdcert.in imap/mkpop3dcert.in;		\
	do								\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|^IMAPDSTART=.*|IMAPDSTART=YES|g"		\
			-e "s|^IMAPDSSLSTART=.*|IMAPDSSLSTART=YES|g"	\
			-e "s|^POP3DSTART=.*|POP3DSTART=YES|g"		\
			-e "s|^POP3DSSLSTART=.*|POP3DSSLSTART=YES|g"	\
			-e "s|@datadir@/imapd.pem|@SSLCERTS@/imapd.pem|g" \
			-e "s|@datadir@/imapd.rand|@sysconfdir@/imapd.rand|g" \
			-e "s|@datadir@/pop3d.pem|@SSLCERTS@/pop3d.pem|g" \
			-e "s|@datadir@/pop3d.rand|@sysconfdir@/pop3d.rand|g" \
			$${file}.fixme > $${file};			\
		if [ -x $${file}.fixme ]; then				\
			${CHMOD} +x $${file};				\
		fi;							\
		${RM} $${file}.fixme;					\
	done

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysconftool ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/courier
	${INSTALL_DATA} ${WRKSRC}/imap/README				\
		${PREFIX}/share/doc/courier/README.imap
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${PREFIX}/share/doc/courier/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${PREFIX}/share/doc/courier/README.sharedfolders
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
