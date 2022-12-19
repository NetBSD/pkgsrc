===========================================================================
$NetBSD: README.NetBSD.txt,v 1.1 2022/12/19 14:54:10 gdt Exp $

The following mail from Steve Bellovin, which can also be viewed at

	http://mail-index.netbsd.org/current-users/2002/07/15/0006.html

is relevant to users of this package:

Delivered-To: current-users@netbsd.org
From: "Steven M. Bellovin" <smb@research.att.com>
To: current-users@netbsd.org
Subject: Re: CFS with NetBSD 1.6
Date: Mon, 15 Jul 2002 14:00:59 +0900
Precedence: list

In message <20020630000510.2a034cf4.520079546242-0001@t-online.de>, Michael Cor
e writes:
>Hi,
>
>is cfsd still useable with NetBSD 1.6? I haven't used it for a while and
>now I cannot access the files in my cfs'd directory anymore. cfs_attach
>works and I can walk the directories but the moment I access a file
>(with cat, less or whatever) the program or shell stalls. top shows that
>cfsd waits in "select" and several nfsio show "nfsidl". I'll give it
>another try with a GENERIC-kernel but I'm afraid that isn't the problem.
>

The problem turns out to be NFS blocksize -- I got the idea from some
other discussions about problems caused by the change in the default
blocksize.  The fix is to use the following mount command:

        mount -o intr,-2,-w=4096,-r=4096 127.0.0.1:/null /crypt

8192 doesn't work; I haven't yet groveled through the CFS source to
figure out why.

                --Steve Bellovin, http://www.research.att.com/~smb (me)
                http://www.wilyhacker.com ("Firewalls" book)


===========================================================================
