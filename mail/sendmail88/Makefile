# $NetBSD: Makefile,v 1.1.1.1 2000/02/13 00:14:48 tron Exp $

DISTNAME=	sendmail.8.8.8
PKGNAME=	sendmail-8.8.8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/sendmail/ \
		ftp://ftp.kyoto.wide.ad.jp/pub/mail/sendmail/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sendmail.org/

MANCOMPRESSED_IF_MANZ= YES
MESSAGE_FILE=	${WRKSRC}/MESSAGE
WRKSRC=		${WRKDIR}/${PKGNAME}

M4DIR=		${PREFIX}/share/sendmail
M4FILES=	README domain/Berkeley.EDU.m4 \
		domain/CS.Berkeley.EDU.m4 \
		domain/EECS.Berkeley.EDU.m4 \
		domain/S2K.Berkeley.EDU.m4 \
		domain/generic.m4 \
		domain/berkeley-only.m4 \
		feature/allmasquerade.m4 \
		feature/always_add_domain.m4 \
		feature/bestmx_is_local.m4 \
		feature/bitdomain.m4 \
		feature/domaintable.m4 \
		feature/genericstable.m4 \
		feature/limited_masquerade.m4 \
		feature/local_procmail.m4 \
		feature/mailertable.m4 \
		feature/masquerade_entire_domain.m4 \
		feature/masquerade_envelope.m4 \
		feature/nocanonify.m4 \
		feature/nodns.m4 \
		feature/notsticky.m4 \
		feature/nouucp.m4 \
		feature/nullclient.m4 \
		feature/redirect.m4 \
		feature/smrsh.m4 \
		feature/stickyhost.m4 \
		feature/use_ct_file.m4 \
		feature/use_cw_file.m4 \
		feature/uucpdomain.m4 \
		feature/virtusertable.m4 \
		hack/cssubdomain.m4 \
		m4/cf.m4 \
		m4/cfhead.m4 m4/nullrelay.m4 \
		m4/proto.m4 \
		m4/version.m4 \
		mailer/cyrus.m4 \
		mailer/fax.m4 \
		mailer/local.m4 \
		mailer/mail11.m4 \
		mailer/phquery.m4 \
		mailer/pop.m4 \
		mailer/procmail.m4 \
		mailer/smtp.m4 \
		mailer/usenet.m4 \
		mailer/uucp.m4 \
		ostype/aix2.m4 \
		ostype/aix3.m4 \
		ostype/aix4.m4 \
		ostype/altos.m4 \
		ostype/amdahl-uts.m4 \
		ostype/aux.m4 \
		ostype/bsd4.3.m4 \
		ostype/bsd4.4.m4 \
		ostype/bsdi1.0.m4 \
		ostype/bsdi2.0.m4 \
		ostype/dgux.m4 \
		ostype/domainos.m4 \
		ostype/dynix3.2.m4 \
		ostype/gnuhurd.m4 \
		ostype/hpux10.m4 \
		ostype/hpux9.m4 \
		ostype/irix4.m4 \
		ostype/irix5.m4 \
		ostype/irix6.m4 \
		ostype/isc4.1.m4 \
		ostype/linux.m4 \
		ostype/maxion.m4 \
		ostype/mklinux.m4 \
		ostype/nextstep.m4 \
		ostype/osf1.m4 \
		ostype/powerux.m4 \
		ostype/ptx2.m4 \
		ostype/riscos4.5.m4 \
		ostype/sco3.2.m4 \
		ostype/sco-uw-2.1.m4 \
		ostype/sinix.m4 \
		ostype/solaris2.m4 \
		ostype/solaris2.ml.m4 \
		ostype/sunos3.5.m4 \
		ostype/sunos4.1.m4 \
		ostype/svr4.m4 \
		ostype/ultrix4.m4 \
		ostype/unknown.m4 \
		ostype/uxpds.m4 \
		sh/makeinfo.sh \
		siteconfig/uucp.cogsci.m4 \
		siteconfig/uucp.old.arpa.m4 \
		siteconfig/uucp.ucbarpa.m4 \
		siteconfig/uucp.ucbvax.m4

post-extract:
	@${CHMOD} -R +w ${WRKSRC}

do-configure:
	cd ${WRKSRC}; \
	for FILE in ${FILESDIR}/${MAKEFILE} ${FILESDIR}/${MAKEFILE}.inc \
	  ${FILESDIR}/mailer.conf ${PKGDIR}/MESSAGE; do \
	  ${CP} $${FILE} .; \
	done; \
	${CP} ${FILESDIR}/netbsd-proto.mc ${WRKSRC}/cf/cf; \
	for FILE in MESSAGE cf/README cf/feature/smrsh.m4 mailer.conf; do \
	  ${CP} $${FILE} tempfile; \
	  ${SED} -e 's#@@PKGNAME@@#${PKGNAME}#g' \
	    -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <tempfile >$${FILE}; \
	  ${RM} -f tempfile; \
	done

pre-install:
	${MKDIR} ${PREFIX}/libexec/sendmail ${M4DIR} ${M4DIR}/cf \
	  ${M4DIR}/domain ${M4DIR}/feature ${M4DIR}/hack ${M4DIR}/m4 \
	  ${M4DIR}/mailer ${M4DIR}/ostype ${M4DIR}/siteconfig \
	  ${M4DIR}/mailer ${M4DIR}/sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/mailer.conf \
	  ${PREFIX}/etc/mailer.conf.sendmail
	for FILE in ${M4FILES}; do \
	  ${INSTALL_DATA} ${WRKSRC}/cf/$${FILE} ${M4DIR}/$${FILE}; \
	done

.include "../../mk/bsd.pkg.mk"

.for OPT in ${MANINSTALL}
PLIST_SRC+=	${PKGDIR}/PLIST.${OPT}
.endfor
