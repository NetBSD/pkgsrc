===========================================================================
$NetBSD: README.pkgsrc.txt,v 1.1 2023/01/31 18:53:46 nikita Exp $

To enable this package, put the following into your /etc/rc.conf:

	gnunet=YES

and ensure that

	${RCD_SCRIPTS_DIR}/gnunet start

is run at the appropriate time.
Each GNUnet user should be added to the ${GNUNET_GROUP}.

Each GNUnet user must add a ~/.config/gnunet.conf file
with these lines:

[arm]
START_SYSTEM_SERVICES = NO
START_USER_SERVICES = YES


Finally, each user in this multi-user setup, must start
gnunet with "gnunet-arm -s".

You can achieve this (for one user) with this in your /etc/rc.conf:

        gnunetuser=YES
        gnunetuser_user=name
        gnunetuser_user_home="/home/name"

if your user name is "name", and

	${RCD_SCRIPTS_DIR}/gnunetuser start

Read the documentation (info gnunet) and provided example
files as well as the man pages to learn how to customize
your peer configuration. An online documentation is
provided at https://docs.gnunet.org/ as well as offline at
${PREFIX}/share/doc/gnunet/html/index.html.
===========================================================================
