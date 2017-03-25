\NeedsTeXFormat{pLaTeX2e}
\ProvidesClass{plnews}[1997/02/01 v1.0a Standard pLaTeX class]

\InputIfFileExists{polnews.cfg}%
  {\ClassInfo{plnews}{Using local configuration file}}%
  {\ClassInfo{plnews}{No local configuration file}}

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{plnews}}
\ProcessOptions
\LoadClass[a4j,twocolumn,oneside]{jarticle}
\RequirePackage{shortvrb}
\MakeShortVerb{\|}
\setlength{\footskip}{15mm}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% \maketitle parameters.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\title{p\LaTeX~ニュース}
\newcommand{\@titlefont}{\normalfont\Huge}

\newcommand{\publicationmonth}{\renewcommand{\@month}}
\newcommand{\@month}{\ClassError{ltnews}
   {No \protect\publicationmonth~given}\@eha}

\newcommand{\publicationyear}{\renewcommand{\@year}}
\newcommand{\@year}{\ClassError{ltnews}
   {No \protect\publicationyear~given}\@eha}

\newcommand{\publicationissue}{\renewcommand{\@issue}}
\newcommand{\@issue}{\ClassError{ltnews}
   {No \protect\publicationissue~given}\@eha}
\newcommand{\issuename}{Issue}

\renewcommand{\maketitle}{%
   \twocolumn[{%
      \parbox[t][7\baselineskip]{\textwidth}{%
         \@titlefont\@title\hspace{3mm}%
         \normalsize 第{\@issue}号\\[\medskipamount]
         \normalfont{\@year}年{\@month}月~発行\\
         作成者：\begin{tabular}[t]{l}
                 \@author
                 \end{tabular}%
      }%
   }]%
}

\newcommand{\ps@titlepage}{%
   \renewcommand{\@oddhead}{\hfill}%
   \renewcommand{\@evenhead}{\hfill}%
   \renewcommand{\@oddfoot}{\@title~第{\@issue}号\hfil\thepage}%
   \renewcommand{\@evenfoot}{\@title~第{\@issue}号\hfil\thepage}%
}
\pagestyle{titlepage}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Sectioning
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand{\section}{%
    \@startsection{section}{1}{\z@}
       {1.5\Cvs \@plus.6\Cvs \@minus.2\Cvs}%
       {.5\Cvs \@plus.3\Cvs}{\reset@font\Large\bfseries}
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Page Layout
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\setlength{\topmargin}{0pt}
\setlength{\headheight}{0pt}
\setlength{\headsep}{0pt}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% itemize
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewenvironment{itemize}
  {\ifnum \@itemdepth >3\relax\@toodeep\else
   \advance\@itemdepth\@ne
   \edef\@itemitem{labelitem\romannumeral\the\@itemdepth}%
   \expandafter
   \list{\csname \@itemitem\endcsname}{%
      \iftdir
         \ifnum \@listdepth=\@ne \topsep.5\normalbaselineskip
           \else\topsep\z@\fi
         \labelwidth1zw \labelsep.3zw
         \ifnum \@itemdepth =\@ne \leftmargin1zw\relax
           \else\leftmargin\leftskip\fi
         \advance\leftmargin 1zw
      \fi
      \parskip\z@ \itemsep\z@ \parsep\z@ % KN 1998/08/10
      \def\makelabel##1{\hss\llap{##1}}}%
   \fi}{\endlist}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% misc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\file#1{\textsf{#1}}
\def\option#1{\texttt{#1}}
\xspcode"5C=3  % \
\xspcode"3C=3  % <
\xspcode"3E=3  % >

\endinput
