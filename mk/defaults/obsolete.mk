# $NetBSD: obsolete.mk,v 1.3 2005/02/07 11:35:41 jlam Exp $
#
# This file holds make(1) logic to allow obsolete or deprecated variables
# still to be used.  These may eventually disappear over time as the contents
# are, by definition, obsolete and deprecated.

.if defined(PRIV_CONF_DIR)
PKG_SYSCONFDIR.priv?=	${PRIV_CONF_DIR}
.endif

###
### Set PKG_DEFAULT_OPTIONS based on global variable settings.
###
.if defined(KERBEROS)
.  if ${KERBEROS} == "4"
PKG_DEFAULT_OPTIONS+=	kerberos4
.  else
PKG_DEFAULT_OPTIONS+=	kerberos
.  endif
.endif
.if defined(USE_CANNA) && !empty(USE_CANNA:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	canna
.endif
.if defined(USE_CUPS) && !empty(USE_CUPS:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	cups
.endif
.if defined(USE_DB4) && !empty(USE_DB4:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	db4
.endif
.if defined(USE_ESOUND) && !empty(USE_ESOUND:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	esound
.endif
.if defined(USE_GIF)
PKG_DEFAULT_OPTIONS+=	gif
.endif
.if defined(USE_I586) && !empty(USE_I586:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	i586
.endif
.if defined(USE_IDEA) && !empty(USE_IDEA:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	idea
.endif
.if defined(USE_INN) && !empty(USE_INN:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	inn
.endif
.if defined(USE_LIBCRACK) && !empty(USE_LIBCRACK:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	libcrack
.endif
.if defined(USE_MMX) && !empty(USE_MMX:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	mmx
.endif
.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ldap
.endif
.if defined(USE_OSS)
PKG_DEFAULT_OPTIONS+=	oss
.endif
.if defined(USE_RSAREF2) && !empty(USE_RSAREF2:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	rsaref
.endif
.if defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sasl
.endif
.if defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sasl
.endif
.if defined(USE_SJ3) && !empty(USE_SJ3:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sj3
.endif
.if defined(USE_SOCKS)
.  if ${USE_SOCKS} == "4"
PKG_DEFAULT_OPTIONS+=	socks4
.  elif ${USE_SOCKS} == "5"
PKG_DEFAULT_OPTIONS+=	socks5
.  endif
.endif
.if defined(USE_WNN4) && !empty(USE_WNN4:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	wnn4
.endif
.if defined(USE_XFACE) && !empty(USE_XFACE:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	xface
.endif
